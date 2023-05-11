#include "defs.h"

extern "C" void ebreak() {
	npc_end = true;
}

extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
  cpu.gpr = (uint64_t *)(((VerilatedDpiOpenVar*)r)->datap());
}

extern "C" void set_ptr(void *ptr, int flag) {
	switch (flag) {
		case 0: pc = (vaddr_t *)ptr; break;
		case 1: inst = (uint32_t *)ptr; break;
		default: assert(0);
	}	
}

extern "C" void npc_vmem_read(long long raddr, long long *rdata) {
  // 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
	*rdata = paddr_read((vaddr_t)raddr, 8);
}

extern "C" void npc_vmem_write(long long waddr, long long wdata, char wmask) {
  // 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
	switch (wmask)
	{
	case 0x1:
		paddr_write((vaddr_t)waddr, 1, (word_t)wdata);
		break;
	case 0x3:
		paddr_write((vaddr_t)waddr, 2, (word_t)wdata);
		break;
	case 0xf:
		paddr_write((vaddr_t)waddr, 4, (word_t)wdata);
		break;
	case (char)0xff:
		paddr_write((vaddr_t)waddr, 8, (word_t)wdata);
		break;
	default:
		Error("wmask not implemented\n");
	}
}