#!/bin/bash

echo "------INNO-MAKER LCD35 CT auto install script  v0.1------"

strVersion=$(awk -F " " '{print $3}' /proc/version)
strModel=$(cat /proc/device-tree/model)

echo $strVersion
echo $strModel

version=0
model=0

case $strVersion in
        *5.10.17*)
                version=5.10.17
        ;;
        *5.4.83*)
                version=5.4.83
        ;;

        *5.4.51*)
                version=5.4.51
        ;;
        *4.19.118*)
                version=4.19.118
        ;;
        *4.19.97*)
                version=4.19.97
        ;;
        *4.19.57*)
                version=4.19.57
        ;;
	*)
                echo "@ Linux Version Not Match! Please contact support@inno-maker.com"
        ;;
esac

case $strModel in
	*Pi' '4*)
		model=pi4
	;;
	*Pi' '3*)
		model=pi3
	;;
        *Pi' 'Compute' 'Module' '4*)
		model=pi4
	;;
	*)
                echo "@ HW Version Not Match! Please contact support@inno-maker.com"
        ;;
esac

if [[ $version == 0 || $model == 0 ]]; then
	echo "@ Install Failed, Please contact support@inno-maker.com"
	exit
fi

sudo chmod -R a+rwx *

cd $version/$model
echo "PWD: "$(pwd)

echo "-----make install----START:"
make install
echo "-----make install----END."

echo "-----lcd setup---START."
cd ../../lcd_setup
./setup.sh
echo "-----lcd setup---END."


echo "INNO-MAKER: reboot now?(y/n):"
read KB_INPUT
case $KB_INPUT in
	'y'|'Y')
		echo "reboot..."
		sudo reboot
	;;
	*)
		echo "cancel."
	;;
esac

















