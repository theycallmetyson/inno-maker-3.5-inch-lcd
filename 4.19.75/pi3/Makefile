###########################
#Makefile
#Fbtft module  driver
#Author:jack
###########################

CONTROL_NAME = ili9486
TOUCH_NAME   = ft6236
ENC_NAME     = ili9486-i2c

############################

CONTROL_DRIVER_DIR =fbtft
CONTROL_DRIVER   =fb_$(CONTROL_NAME)
TOUCH_DRIVER_DIR =touch
TOUCH_DRIVER     =$(TOUCH_NAME)
ENC_DRIVER       =$(ENC_NAME)
KERNEL_MODULE_DIR  =/lib/modules/$(shell uname -r)
KERNEL_BUILD_DIR   =$(KERNEL_MODULE_DIR)/build
KERNEL_CONTROL_DIR =$(KERNEL_MODULE_DIR)/kernel/drivers/staging/fbtft
KERNEL_TOUCH_DIR   =$(KERNEL_MODULE_DIR)/kernel/drivers/input/touchscreen
KERNEL_ENC_DIR     =$(KERNEL_MODULE_DIR)/kernel/drivers/input/touchscreen
BOOT_OVERLAYS_DIR  =/boot/overlays


.PHONY: all


devicetree-install:
	sudo install -p -m 644  lcd35_spi.dtbo  $(BOOT_OVERLAYS_DIR)

#install:  devicetree-install
install:
	sudo install -p -m 644 $(TOUCH_DRIVER_DIR)/$(TOUCH_DRIVER).ko   $(KERNEL_TOUCH_DIR)/
	sudo install -p -m 644 $(ENC_NAME).ko   $(KERNEL_ENC_DIR)/
	sudo install -p -m 644 lcd35_spi.dtbo  $(BOOT_OVERLAYS_DIR)/
	sudo install -p -m 644 99-fbturbo.conf  /usr/share/X11/xorg.conf.d/
	sudo install -p -m 644  $(CONTROL_DRIVER_DIR)/fbtft.ko $(KERNEL_CONTROL_DIR)/
	sudo install -p -m 644  $(CONTROL_DRIVER_DIR)/fbtft_device.ko $(KERNEL_CONTROL_DIR)/
	sudo install -p -m 644  $(CONTROL_DRIVER_DIR)/fb_ili9486.ko $(KERNEL_CONTROL_DIR)/
	sudo /sbin/depmod -a $(shell uname -r)
	sudo /sbin/modprobe $(TOUCH_DRIVER) 
	sudo /sbin/modprobe $(ENC_NAME) 
	sudo /sbin/modprobe fbtft
	sudo /sbin/modprobe fbtft_device
	sudo /sbin/modprobe fbtft_ili9486
	@echo "--------------------------------------"
	@echo
	@echo "  ADD 'dtparam=i2c_arm=on' and 'dtoverlay=lcd35_spi' to your /boot/config.txt"
	@echo "  ADD 'disable_touchscreen=1' to your /boot/config.txt if a touchscreen is attached"
	@echo "  ADD 'cma=128M' to your /boot/cmdline.txt"
	@echo
	@echo "--------------------------------------"

rmmod:
	sudo /sbin/modprobe  -r fb_ili9486
	sudo /sbin/modprobe  -r fbtft_device
	sudo /sbin/modprobe  -r fbtft
	sudo /sbin/modprobe  -r $(ENC_NAME) 
	sudo /sbin/modprobe  -r $(TOUCH_DRIVER) 

uninstall:
	sudo rm -f $(KERNEL_TOUCH_DIR)/$(TOUCH_DRIVER).ko
	sudo rm -f $(KERNEL_ENC_DIR)/$(ENC_NAME).ko
	sudo rm -f $(KERNEL_CONTROL_DIR)/fbtft.ko
	sudo rm -f $(KERNEL_CONTROL_DIR)/fbtft_device.ko
	sudo rm -f $(KERNEL_CONTROL_DIR)/fb_ili9486.ko
	sudo rm -f $(BOOT_OVERLAYS_DIR)/lcd35_spi.dtbo
	sudo /sbin/depmod -a $(shell uname -r)
	@echo "--------------------------------------"
	@echo
	@echo "  REMOVE 'dtparam=i2c_arm=on' and 'dtoverlay=toverlay=lcd35_spi' from your /boot/config.txt"
	@echo "  REMOVE 'cma=128M' from your /boot/cmdline.txt"
	@echo
	@echo "--------------------------------------"



