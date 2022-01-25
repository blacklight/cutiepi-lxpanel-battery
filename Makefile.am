SUBDIRS = src

EXTRA_DIST = \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

install-exec-hook:
	rm -f $(LXPANEL_LIBDIR)/plugins/cutiepi_battery.la
	rm -f $(LXPANEL_LIBDIR)/plugins/cutiepi_battery.a
	rm -f $(LXPANEL_LIBDIR)/plugins/cutiepi_battery.so
