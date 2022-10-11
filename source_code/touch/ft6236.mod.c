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
	{ 0x18321fdf, "i2c_del_driver" },
	{ 0x2b8189c2, "i2c_register_driver" },
	{ 0x58cb3251, "input_mt_sync_frame" },
	{ 0xaef1abbf, "input_mt_report_slot_state" },
	{ 0xa2a2612c, "input_event" },
	{ 0x8da6585d, "__stack_chk_fail" },
	{ 0xdc88f81d, "_dev_err" },
	{ 0xd247cbc7, "input_register_device" },
	{ 0xbdfa71f9, "devm_request_threaded_irq" },
	{ 0x9e6e7eac, "input_mt_init_slots" },
	{ 0x44e9bc98, "input_set_abs_params" },
	{ 0x2047d0c9, "device_property_present" },
	{ 0x2aaba2e8, "device_property_read_u32_array" },
	{ 0xa6a07a55, "devm_input_allocate_device" },
	{ 0xec4d56c1, "i2c_smbus_read_i2c_block_data" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x7159b62c, "gpiod_set_value_cansleep" },
	{ 0xc3d4409e, "devm_gpiod_get_optional" },
	{ 0x4cd3ff7e, "devm_kmalloc" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:ft6236");
MODULE_ALIAS("of:N*T*Cfocaltech,ft6236");
MODULE_ALIAS("of:N*T*Cfocaltech,ft6236C*");

MODULE_INFO(srcversion, "D1FD083835A6490C5684B1A");
