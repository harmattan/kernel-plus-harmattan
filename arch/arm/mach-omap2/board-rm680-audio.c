/*
 * linux/arch/arm/mach-omap2/board-rm680-audio.c
 *
 * Copyright (C) 2009 Nokia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>

#include <asm/mach-types.h>
#include <plat/dfl61-audio.h>

static struct dfl61audio_twl4030_platform_data rm680_twl4030_data;

static struct platform_device rm680_twl4030_device = {
	.name          = "dfl61audio-twl4030",
	.id            = -1,
	.dev            = {
		.platform_data = &rm680_twl4030_data,
	},
};

static int __init rm680_audio_init(void)
{
	if (!machine_is_nokia_rm680())
		return 0;

	rm680_twl4030_data.audio_config = AUDIO_CONFIG4;
	rm680_twl4030_data.freq = 38400000;

	platform_device_register(&rm680_twl4030_device);
	return 0;
}

subsys_initcall(rm680_audio_init);
