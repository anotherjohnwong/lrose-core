/*
 * regis_tool_ui.c - User interface object initialization functions.
 * This file was generated by `gxv' from `regis_tool.G'.
 * DO NOT EDIT BY HAND.
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/types.h>
#include <xview/xview.h>
#include <xview/canvas.h>
#include <xview/panel.h>
#include <xview/scrollbar.h>
#include <xview/svrimage.h>
#include <xview/termsw.h>
#include <xview/text.h>
#include <xview/tty.h>
#include <xview/xv_xrect.h>
#include <gcm.h>
#include "regis_tool_ui.h"

/*
 * Initialize an instance of object `win1'.
 */
regis_tool_win1_objects *
regis_tool_win1_objects_initialize(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	if (!ip && !(ip = (regis_tool_win1_objects *) calloc(1, sizeof (regis_tool_win1_objects))))
		return (regis_tool_win1_objects *) NULL;
	if (!ip->win1)
		ip->win1 = regis_tool_win1_win1_create(ip, owner);
	if (!ip->controls1)
		ip->controls1 = regis_tool_win1_controls1_create(ip, ip->win1);
	if (!ip->start_bt)
		ip->start_bt = regis_tool_win1_start_bt_create(ip, ip->controls1);
	if (!ip->comp_bt)
		ip->comp_bt = regis_tool_win1_comp_bt_create(ip, ip->controls1);
	if (!ip->status_msg)
		ip->status_msg = regis_tool_win1_status_msg_create(ip, ip->controls1);
	if (!ip->each_pt_msg)
		ip->each_pt_msg = regis_tool_win1_each_pt_msg_create(ip, ip->controls1);
	if (!ip->avg_msg)
		ip->avg_msg = regis_tool_win1_avg_msg_create(ip, ip->controls1);
	return ip;
}

/*
 * Create object `win1' in the specified instance.
 */
Xv_opaque
regis_tool_win1_win1_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, FRAME,
		XV_KEY_DATA, INSTANCE, ip,
		XV_WIDTH, 266,
		XV_HEIGHT, 114,
		XV_LABEL, "Registration Tool",
		FRAME_SHOW_FOOTER, FALSE,
		FRAME_SHOW_RESIZE_CORNER, FALSE,
		NULL);
	return obj;
}

/*
 * Create object `controls1' in the specified instance.
 */
Xv_opaque
regis_tool_win1_controls1_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 0,
		XV_Y, 0,
		XV_WIDTH, WIN_EXTEND_TO_EDGE,
		XV_HEIGHT, WIN_EXTEND_TO_EDGE,
		WIN_BORDER, FALSE,
		NULL);
	gcm_initialize_colors(obj, "Dim Gray", "White");
	return obj;
}

/*
 * Create object `start_bt' in the specified instance.
 */
Xv_opaque
regis_tool_win1_start_bt_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		start_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 16,
		PANEL_LABEL_STRING, "Start",
		PANEL_NOTIFY_PROC, start_proc,
		NULL);
	return obj;
}

/*
 * Create object `comp_bt' in the specified instance.
 */
Xv_opaque
regis_tool_win1_comp_bt_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	extern void		comp_proc();
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_BUTTON,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 68,
		XV_Y, 16,
		PANEL_LABEL_STRING, "Store",
		PANEL_NOTIFY_PROC, comp_proc,
		NULL);
	return obj;
}

/*
 * Create object `status_msg' in the specified instance.
 */
Xv_opaque
regis_tool_win1_status_msg_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 45,
		PANEL_ITEM_COLOR, gcm_color_index("White"),
		PANEL_LABEL_STRING, "Ready to Start",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `each_pt_msg' in the specified instance.
 */
Xv_opaque
regis_tool_win1_each_pt_msg_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 68,
		PANEL_ITEM_COLOR, gcm_color_index("White"),
		PANEL_LABEL_STRING, "No Points.",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

/*
 * Create object `avg_msg' in the specified instance.
 */
Xv_opaque
regis_tool_win1_avg_msg_create(ip, owner)
	regis_tool_win1_objects	*ip;
	Xv_opaque	owner;
{
	Xv_opaque	obj;
	
	obj = xv_create(owner, PANEL_MESSAGE,
		XV_KEY_DATA, INSTANCE, ip,
		XV_X, 8,
		XV_Y, 91,
		PANEL_ITEM_COLOR, gcm_color_index("White"),
		PANEL_LABEL_STRING, "X:               Y:               ",
		PANEL_LABEL_BOLD, TRUE,
		NULL);
	return obj;
}

