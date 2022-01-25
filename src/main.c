/**
 *
 * Copyright (c) 2022 Fabio Manganiello, see the file AUTHORS for details.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <stdio.h>
#include <lxpanel/plugin.h>

#define LabelSize 32

GtkWidget *constructor(LXPanel *panel, config_setting_t *settings)
{
 /* panel is a pointer to the panel and
     settings is a pointer to the configuration data
     since we don't use it, we'll make sure it doesn't
     give us an error at compilation time */
 (void)panel;
 (void)settings;

 // make a label out of the hostname
 char cIdBuf[LabelSize+1] = {'\0'};
 FILE *fp;
 fp = fopen("/etc/hostname", "r");
 fgets(cIdBuf, LabelSize, fp);
 fclose(fp);

 // create a label widget instance
 GtkWidget *pLabel = gtk_label_new(cIdBuf);

 // set the label to be visible
 gtk_widget_show(pLabel);

 // need to create a container to be able to set a border
 GtkWidget *p = gtk_event_box_new();

 // our widget doesn't have a window...
 // it is usually illegal to call gtk_widget_set_has_window() from application but for GtkEventBox it doesn't hurt
 gtk_widget_set_has_window(p, FALSE);

 // set border width
 gtk_container_set_border_width(GTK_CONTAINER(p), 1);

 // add the label to the container
 gtk_container_add(GTK_CONTAINER(p), pLabel);

 // set the size we want
 // gtk_widget_set_size_request(p, 100, 25);

 // success!!!
 return p;
}

FM_DEFINE_MODULE(lxpanel_gtk, test)

/* Plugin descriptor. */
LXPanelPluginInit fm_module_init_lxpanel_gtk = {
   .name = "CutiePi battery",
   .description = "Displays the current state of the CutiePi battery",
   .one_per_system = 1,

   // assigning our functions to provided pointers.
   .new_instance = constructor
};
