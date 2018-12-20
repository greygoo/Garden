from GardenLib import *
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class MyWindow(Gtk.Window):

    def __init__(self, ser):
        Gtk.Window.__init__(self, title="Garden Control")

        self.ser = ser

        grid = Gtk.Grid()
        self.add(grid)

        button_fan0on = Gtk.Button(label="Fan ON")
        button_fan0on.connect("clicked", self.on_button_fan0on_clicked)

        button_fan0off = Gtk.Button(label="Fan OFF")
        button_fan0off.connect("clicked", self.on_button_fan0off_clicked)

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

        ad1 = Gtk.Adjustment(0, 0, 100, 5, 10, 0)
        self.scale_fanspeed = Gtk.Scale(orientation = Gtk.Orientation.HORIZONTAL, adjustment=ad1)
        self.scale_fanspeed.set_hexpand(True)
        self.scale_fanspeed.set_valign(Gtk.Align.START)
        self.scale_fanspeed.connect("value-changed", self.on_scale_fanspeed_moved)

        grid.add(button_fan0on)
        grid.attach_next_to(button_fan0off, button_fan0on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_pump0on, button_fan0on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_pump0off, button_pump0on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_pump1on, button_pump0on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_pump1off, button_pump1on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(button_lighton, button_pump1on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(button_lightoff, button_lighton, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(self.scale_fanspeed, button_fan0off, Gtk.PositionType.BOTTOM, 1, 1)

    def on_button_fan0on_clicked(self, widget):
        print("Turn on fan0")
        fanOn(self.ser, 0)

    def on_button_fan0off_clicked(self, widget):
        print("Turn off fan 0")
        fanOff(self.ser, 0)

    def on_button_pump0on_clicked(self, widget):
        print("Turn on pump0")
        pumpOn(self.ser,0)

    def on_button_pump0off_clicked(self, widget):
        print("Turn on pump1")
        pumpOff(self.ser,0)

    def on_button_pump1on_clicked(self, widget):
        print("Turn on pump1on")
        pumpOn(self.ser, 1)

    def on_button_pump1off_clicked(self, widget):
        print("Turn on pump1off")
        pumpOff(self.ser,1)

    def on_button_lighton_clicked(self, widget):
        print("Turn on lighton")
        lightOn(self.ser)

    def on_button_lightoff_clicked(self, widget):
        print("Turn on lightoff")
        lightOff(self.ser)

    def on_scale_fanspeed_moved(self, event):
        fan_speed = int(self.scale_fanspeed.get_value())
        print("Fan Speed is " + str(fan_speed))
        fanSpeed(self.ser, fan_speed)
