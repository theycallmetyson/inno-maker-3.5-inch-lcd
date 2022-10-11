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
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7d0b00ef, "module_layout" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xea329813, "device_remove_file" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb5b54b34, "_raw_spin_unlock" },
	{ 0x42aa8513, "devm_gpiod_get_index_optional" },
	{ 0x98cf60b3, "strlen" },
	{ 0x5ca8083c, "framebuffer_release" },
	{ 0x1b07c888, "fb_sys_read" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0x999e8297, "vfree" },
	{ 0xd889a108, "sys_copyarea" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x63588ed8, "of_prop_next_u32" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xfe6bc7c7, "_dev_warn" },
	{ 0xdcb764ad, "memset" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbc7f7024, "of_find_property" },
	{ 0xfbf32098, "of_property_read_string" },
	{ 0xea5c3818, "register_framebuffer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xdc88f81d, "_dev_err" },
	{ 0x9fcaf069, "of_match_device" },
	{ 0x865d3282, "spi_sync" },
	{ 0x61651be, "strcat" },
	{ 0xb450d698, "device_create_file" },
	{ 0xcc656c0a, "_dev_info" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x365864b4, "sys_fillrect" },
	{ 0xfe916dc6, "hex_dump_to_buffer" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x8da6585d, "__stack_chk_fail" },
	{ 0x703f709d, "sys_imageblit" },
	{ 0x92997ed8, "_printk" },
	{ 0x732a7b2, "fb_sys_write" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x181111ac, "framebuffer_alloc" },
	{ 0x7192d203, "fb_deferred_io_cleanup" },
	{ 0xfbab56fd, "fb_deferred_io_init" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x37a0cba, "kfree" },
	{ 0x4829a47e, "memcpy" },
	{ 0x96848186, "scnprintf" },
	{ 0x7159b62c, "gpiod_set_value_cansleep" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x77bc13a0, "strim" },
	{ 0xc7863b93, "of_property_read_variable_u32_array" },
	{ 0x94bc68e8, "gpiod_set_value" },
	{ 0x4cd3ff7e, "devm_kmalloc" },
	{ 0x454cf577, "param_ops_ulong" },
	{ 0xaa0c318b, "vscnprintf" },
	{ 0xbab1e6fd, "unregister_framebuffer" },
};

MODULE_INFO(depends, "fb_sys_fops,syscopyarea,sysfillrect,sysimgblt");


MODULE_INFO(srcversion, "51FFEE3E2108765463325ED");
