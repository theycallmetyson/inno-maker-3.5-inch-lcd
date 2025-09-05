#!/bin/sh
#Setup EMTOP 3.5 inch TFT and touch panel on RPI!
echo "Setup InnoMaker 3.5 inch TFT and touch panel on RPI!"
sleep 2

#Start setup system common files!
#Setup  Linux kernel cmdline!
#if [ ! -f "/boot/overlays/lcd35_spi.dtbo" ] ;then
if [ ! -f "/etc/udev/rules.d/95-ft6236.rules" ] ;then
sudo mkdir driver_backup
sudo mv /lib/modules/$( uname -r)/kernel/drivers/input/touchscreen/edt-ft5x06.ko.xz  ./driver_backup
sudo mv /lib/modules/$( uname -r)/kernel/drivers/staging/fbtft/fb_ili9486.ko.xz  ./driver_backup
sudo mv /lib/modules/$( uname -r)/kernel/drivers/staging/fbtft/fbtft.ko.xz ./driver_backup
#sudo cp -rf ./boot/cmdline.txt /boot/cmdline.txt
#setup inittab
#sudo cp -rf ./etc/inittab /etc/
#setup device tree overlays!
#sudo cp -rf ./overlays/* /boot/overlays/
#setup touchscreen input device udev rules!
sudo cp ./input_rule/95-ft6x06.rules /etc/udev/rules.d/
sudo cp ./input_rule/95-ft6236.rules /etc/udev/rules.d/
#setup RTC!
#sudo cp -rf ./rtc/hwclock-set /lib/udev/hwclock-set
#setup fbturbo!
#sudo cp -rf ./usr/share/X11/xorg.conf.d/99-fbturbo.conf /usr/share/X11/xorg.conf.d/
else
echo "System common file already installed !"
fi

#copy xinput application on /home/pi dir!
if [ ! -d "/home/$USER/user-app" ]; then
sudo mkdir /home/$USER/user-app
sudo cp -rf  ./user-app/* /home/$USER/user-app/
else
echo "user-app Directory alredy exist!"
fi
#End of setup common files!

if [ ! -d "/etc/X11/xorg.conf.d" ]; then
	sudo mkdir /etc/X11/xorg.conf.d
else
echo "xorg.conf.d Directory already exist!"
fi

if [ "$1" = "0" -o "$#" = "0" ] ; then
#if test "$1" = "0" -o "$#" = "0" ; then
sudo cp -rf ./etc/X11/xorg.conf.d/99-calibration.conf /etc/X11/xorg.conf.d/99-calibration.conf
sudo cp -rf ./etc/X11/xorg.conf.d/99-captouch.conf /etc/X11/xorg.conf.d/99-captouch.conf
sudo cp ./boot/config.txt /boot/config.txt
echo "Configure the LCD display 0 degrees"
elif [ "$1" = "90" ] ; then
#elif test "$1" = "90" ; then
sudo cp -rf ./etc/X11/xorg.conf.d/99-calibration-90.conf /etc/X11/xorg.conf.d/99-calibration.conf
sudo cp -rf ./etc/X11/xorg.conf.d/99-captouch-90.conf /etc/X11/xorg.conf.d/99-captouch.conf
sudo cp ./boot/config-90-ctp.txt /boot/config.txt
echo "Configure the LCD display 90 degrees"
elif [ "$1" = "180" ]; then
sudo cp -rf ./etc/X11/xorg.conf.d/99-calibration-180.conf /etc/X11/xorg.conf.d/99-calibration.conf
sudo cp -rf ./etc/X11/xorg.conf.d/99-captouch-180.conf /etc/X11/xorg.conf.d/99-captouch.conf
sudo cp ./boot/config-180.txt /boot/config.txt
echo "Configure the LCD display 180 degrees"
elif [ "$1" = "270" ]; then
sudo cp -rf ./etc/X11/xorg.conf.d/99-calibration-270.conf /etc/X11/xorg.conf.d/99-calibration.conf
sudo cp -rf ./etc/X11/xorg.conf.d/99-captouch-270.conf /etc/X11/xorg.conf.d/99-captouch.conf
sudo cp ./boot/config-270-ctp.txt /boot/config.txt
echo "Configure the LCD display 270 degrees"
fi

if test "$#" = "0" -o "$1" = "0" -o "$1" = "90" -o "$1" = "180" -o "$1" = "270" ; then
	echo "System setup is complete, restart the system!"
else
	echo "Invalid parameter, Usage:setup.sh [0] [90] [180] [270] "
fi

