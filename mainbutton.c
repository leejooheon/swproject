#include<gtk/gtk.h>

int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;

	gtk_init(&argc,&argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),230,250);
	gtk_window_set_title(GTK_WINDOW(window),"LJProject");
	gtk_container_set_border_width(GTK_CONTAINER(window),3);

	vbox=gtk_vbox_new(TRUE,1);
	gtk_container_add(GTK_CONTAINER(window),vbox);

	button1 = gtk_button_new_with_label("Select User");
	gtk_widget_set_size_request(button1,15,35);
	//insert button1 func
	button2 = gtk_button_new_with_label("input&result");
	gtk_widget_set_size_request(button2,15,35);
	//insert button2 func

	gtk_box_pack_start(GTK_BOX(vbox),button1,TRUE,TRUE,0);
	gtk_box_pack_start(GTK_BOX(vbox),button2,TRUE,TRUE,0);
	g_signal_connect_swapped(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),G_OBJECT(window));

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
