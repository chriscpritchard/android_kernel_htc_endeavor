/*
 * Copyright (C) 2011 NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307, USA
 */

#ifndef __S5K3H2Y_H__
#define __S5K3H2Y_H__

#include <linux/ioctl.h>  /* For IOCTL macros */

#define S5K3H2Y_IOCTL_SET_MODE			_IOW('o', 1, struct s5k3h2y_mode)
#define S5K3H2Y_IOCTL_SET_FRAME_LENGTH	_IOW('o', 2, __u32)
#define S5K3H2Y_IOCTL_SET_COARSE_TIME	_IOW('o', 3, __u32)
#define S5K3H2Y_IOCTL_SET_GAIN			_IOW('o', 4, __u16)
#define S5K3H2Y_IOCTL_GET_STATUS			_IOR('o', 5, __u8)
#define S5K3H2Y_IOCTL_SET_GROUP_HOLD		_IOW('o', 6, struct s5k3h2y_ae)

struct s5k3h2y_mode {
	int xres;
	int yres;
	__u32 frame_length;
	__u32 coarse_time;
	__u16 gain;
};

struct s5k3h2y_ae {
	__u32 frame_length;
	__u8 frame_length_enable;
	__u32 coarse_time;
	__u8 coarse_time_enable;
	__s32 gain;
	__u8 gain_enable;
};

#ifdef __KERNEL__
struct s5k3h2y_platform_data {
	int (*get_power_state)(void);
	int (*power_on)(void);
	int (*power_off)(void);
	void (*synchronize_sensors)(void);
};
#endif /* __KERNEL__ */

#endif  /* __S5K3H2Y_H__ */

