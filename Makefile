PROJ_NAME = SeatTemparature

BUILD_DIR = Build


SRC = project_main.c\
src/Activity1.c\
src/Activity2.c\
src/Activity3.c\
src/Activity4.c


INC = -I inc


ifdef OS	
   FixPath = $(subst /,\,$1)

   CC = avr-gcc.exe

   AVR_OBJ_CPY = avr-objcopy.exe
else 
   ifeq ($(shell uname), Linux)

      FixPath = $1				

	  CC = avr-gcc

	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif


.PHONY:all analysis clean doc

all:$(BUILD_DIR)

	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):

	mkdir $(BUILD_DIR)

analysis: $(SRC)

	cppcheck --enable=all $^

doc:

	make -C documentation

clean:

	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean