#!/usr/bin/python


import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

class MyWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Garden Control")

        grid = Gtk.Grid()
        self.add(grid)

        button_fanon = Gtk.Button(label="Fan ON")
        button_fanon.connect("clicked", self.on_button_fanon_clicked)

        button_fanoff = Gtk.Button(label="Fan OFF")
        button_fanoff.connect("clicked", self.on_button_fanoff_clicked)

        button_pump0on = Gtk.Button(label="Pump0 ON")
        button_pump0on.connect("clicked", self.on_button_pump0on_clicked)

        button_pump0off = Gtk.Button(label="Pump0 OFF")
        button_pump0off.connect("clicked", self.on_button_pump0off_clicked)

        button_pump1on = Gtk.Button(label="Pump1 ON")
        button_pump1on.connect("clicked", self.on_button_pump1on_clicked)

        button_pump1off = Gtk.Button(label="Pump1 OFF")
        button_pump1off.connect("clicked", self.on_button_pump1off_clicked)

        button_lighton = Gtk.Button(label="Light ON")
        button_lighton.connect("clicked", self.on_button_lighton_clicked)

        button_lightoff = Gtk.Button(label="Light OFF")
        button_lightoff.connect("clicked", self.on_button_lightoff_clicked)

        grid.add(button_fanon)
        grid.attach_next_to(button_fanoff, button_fanon, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_pump0on, button_fanon, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_pump0off, button_pump0on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_pump1on, button_pump0on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_pump1off, button_pump1on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_lighton, button_pump1on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_lightoff, button_lighton, Gtk.PositionType.BOTTOM, 1, 1)

    def on_button_fanon_clicked(self, widget):
        print("Turn on fan")

    def on_button_fanoff_clicked(self, widget):
        print("Turn off fan")

    def on_button_pump0on_clicked(self, widget):
        print("Turn on pump0")

    def on_button_pump0off_clicked(self, widget):
        print("Turn on pump1")

    def on_button_pump1on_clicked(self, widget):
        print("Turn on pump1on")

    def on_button_pump1off_clicked(self, widget):
        print("Turn on pump1off")

    def on_button_lighton_clicked(self, widget):
        print("Turn on lighton")

    def on_button_lightoff_clicked(self, widget):
        print("Turn on lightoff")


win = MyWindow()
win.connect("destroy", Gtk.main_quit)
win.show_all()
Gtk.main()
