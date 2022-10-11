###########################
#Makefile
#InnoMaker 3.5 inch Capacitive IPS LCD module  driver
#Author:JackYang
#Copyright : InnoMaker
###########################


obj-m +=fb_ili9486.o
obj-m +=fbtft.o
fbtft-objs := fbtft-core.o fbtft-sysfs.o fbtft-bus.o  fbtft-io.o

.PHONY: all
all: $(KERNEL_BUILD_DIR) 
	make -C $(KERNEL_BUILD_DIR) M=$(shell pwd) modules
clean:
	make -C $(KERNEL_BUILD_DIR) M=$(PWD) clean



