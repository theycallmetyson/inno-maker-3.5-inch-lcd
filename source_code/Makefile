###########################
#Makefile
#InnoMaker 3.5 inch Capacitive IPS LCD module  driver
#Author:Jack Yang
#Copyright : InnoMaker
###########################

CONTROL_NAME = ili9486
TOUCH_NAME   = ft6236

############################

CONTROL_DRIVER_DIR =fbtft
CONTROL_DRIVER   =fb_$(CONTROL_NAME)
TOUCH_DRIVER_DIR =touch
TOUCH_DRIVER     =$(TOUCH_NAME)
KERNEL_MODULE_DIR  =/lib/modules/$(shell uname -r)
KERNEL_BUILD_DIR   =$(KERNEL_MODULE_DIR)/build
KERNEL_CONTROL_DIR =$(KERNEL_MODULE_DIR)/kernel/drivers/staging/fbtft
KERNEL_TOUCH_DIR   =$(KERNEL_MODULE_DIR)/kernel/drivers/input/touchscreen
BOOT_OVERLAYS_DIR  =/boot/overlays

obj-m :=$(TOUCH_DRIVER_DIR)/$(TOUCH_DRIVER).o
obj-m +=fbtft/

.PHONY: all
all: $(KERNEL_BUILD_DIR) devicetree
	make -C $(KERNEL_BUILD_DIR) M=$(shell pwd) modules
clean:
	make -C $(KERNEL_BUILD_DIR) M=$(PWD) clean
	rm -f lcd35_spi.dtbo

devicetree:
	dtc -W no-unit_address_vs_reg -@ -I dts -O dtb -o lcd35_spi.dtbo lcd35_spi_ft6236at_bl_gpio4.dts

devicetree-install: devicetree
	sudo install -p -m 644  lcd35_spi.dtbo  $(BOOT_OVERLAYS_DIR)

install: all devicetree-install
	sudo install -p -m 644 $(TOUCH_DRIVER_DIR)/$(TOUCH_DRIVER).ko   $(KERNEL_TOUCH_DIR)/
	sudo install -p -m 644 lcd35_spi.dtbo  $(BOOT_OVERLAYS_DIR)/
	sudo install -p -m 644  $(CONTROL_DRIVER_DIR)/fbtft.ko $(KERNEL_CONTROL_DIR)/
	sudo install -p -m 644  $(CONTROL_DRIVER_DIR)/fb_ili9486.ko $(KERNEL_CONTROL_DIR)/
	sudo /sbin/depmod -a $(shell uname -r)
	sudo /sbin/modprobe $(TOUCH_DRIVER) 
	sudo /sbin/modprobe fbtft
	sudo /sbin/modprobe fbtft_ili9486
	@echo "--------------------------------------"
	@echo
	@echo "  ADD 'dtparam=i2c_arm=on' and 'dtoverlay=lcd35_spi' to your /boot/config.txt"
	@echo
	@echo "--------------------------------------"

rmmod:
	sudo /sbin/modprobe  -r fb_ili9486
	sudo /sbin/modprobe  -r fbtft
	sudo /sbin/modprobe  -r $(TOUCH_DRIVER) 

uninstall:
	sudo rm -f $(KERNEL_TOUCH_DIR)/$(TOUCH_DRIVER).ko
	sudo rm -f $(KERNEL_CONTROL_DIR)/fbtft.ko
	sudo rm -f $(KERNEL_CONTROL_DIR)/fb_ili9486.ko
	sudo rm -f $(BOOT_OVERLAYS_DIR)/lcd35_spi.dtbo
	sudo /sbin/depmod -a $(shell uname -r)
	@echo "--------------------------------------"
	@echo
	@echo "  REMOVE 'dtparam=i2c_arm=on' and 'dtoverlay=toverlay=lcd35_spi' from your /boot/config.txt"
	@echo
	@echo "--------------------------------------"



