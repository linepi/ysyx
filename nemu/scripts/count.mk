COUNT_SRC = $(shell find ./src -name *.c -o -name *.h | xargs wc -l | grep total)
COUNT_SRC := $(subst \n,,$(COUNT_SRC))
COUNT_TEST = $(shell find ./tests -name *.c | xargs wc -l | tail -n 1 | awk '/[0-9]+/')
COUNT_TEST := $(subst \n,,$(COUNT_TEST))
COUNT_INCLUDE = $(shell find ./include -name *.h | xargs wc -l | grep total) 
COUNT_INCLUDE := $(subst \n,,$(COUNT_INCLUDE))

count: 
	@echo -n "src: "
	@echo -n $(COUNT_SRC)	
	@echo " line"

	@echo -n "test: "
	@echo -n $(COUNT_TEST)	
	@echo " line"

	@echo -n "include: "
	@echo -n $(COUNT_INCLUDE)	
	@echo " line"
.PHONY: count