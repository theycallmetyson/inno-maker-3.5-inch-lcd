#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7d0b00ef, "module_layout" },
	{ 0x417a79b8, "platform_driver_unregister" },
	{ 0x9db4c0a9, "driver_unregister" },
	{ 0x643fd29, "__platform_driver_register" },
	{ 0x9e9e6c8b, "__spi_register_driver" },
	{ 0xebe48e23, "fbtft_probe_common" },
	{ 0xddb0824, "fbtft_remove_common" },
};

MODULE_INFO(depends, "fbtft");

MODULE_ALIAS("of:N*T*Cilitek,ili9486");
MODULE_ALIAS("of:N*T*Cilitek,ili9486C*");

MODULE_INFO(srcversion, "CA319FEC074A89307825BC5");
