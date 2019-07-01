/*
 * Copyright (c) 2019 blkf2016@gmail.com.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ___UBOOT_LOADER_H___
#define ___UBOOT_LOADER_H___

#define UBOOT_LOAD_ADDR		0x04000000
#define UBOOT_BIN_NAME		"u-boot.bin"

u32 UBootLoader(void);

#endif
