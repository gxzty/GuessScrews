#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
	gtk_init(NULL,NULL);
	GtkWindow *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    
	//Make a big grid for everything
	GtkGrid *grid1 = gtk_grid_new();
    
	//need one button for 'OK'
	GtkButton *btn1 = gtk_button_new();
	gtk_button_set_label(btn1,"OK");
    
	//need one entry for input number
	GtkEntry *entry1 = gtk_entry_new();

	//need one labels for display status
	GtkLabel *label1 = gtk_label_new("1");

	//position
    gtk_grid_attach(grid1,entry1,0,1,1,1);
	gtk_grid_attach(grid1,btn1,4,1,1,1);
	gtk_grid_attach(grid1,label1,0,3,3,1);

	//show them up
	gtk_widget_show(grid1);
	gtk_widget_show(window);
	gtk_container_add(window,grid1);
	gtk_widget_show(btn1);
	gtk_widget_show(label1);
	gtk_widget_show(entry1);

    gtk_main();
	return 0;
}
