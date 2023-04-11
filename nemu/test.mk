OBJ_DIR = $(shell pwd)/build
SRCS = a.c b.c c.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

default:
	@echo $(OBJS)
