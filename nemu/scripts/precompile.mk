PRE_FILE_DIR = $(BUILD_DIR)/i-$(NAME)$(SO)
PRE_COMPILE_FLAGS = $(INCLUDES)

HEADERS = $(shell find include -name "*.h")

PRE_FILES = $(SRCS:%.c=$(PRE_FILE_DIR)/%.c)
PRE_FILES += $(HEADERS:%.h=$(PRE_FILE_DIR)/%.h)

precompile: $(PRE_FILES)
# Precompilation patterns
$(PRE_FILE_DIR)/%.c: %.c
	@echo + CC_PRE $<
	@mkdir -p $(dir $@)
	@$(CC) -E $(PRE_COMPILE_FLAGS) $< | grep -v '^#' | clang-format --style=Google > $@

$(PRE_FILE_DIR)/%.h: %.h
	@echo + CC_PRE $<
	@mkdir -p $(dir $@)
	@$(CC) -E $(PRE_COMPILE_FLAGS) $< | grep -v '^#' | clang-format --style=Google > $@

.PHONY: precompile
