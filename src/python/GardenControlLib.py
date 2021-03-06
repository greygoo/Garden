from GardenLib import *
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


class GardenControlWindow(Gtk.Window):

    def __init__(self, ser):
        Gtk.Window.__init__(self, title="Garden Control")
        self.set_size_request(750,550)

        self.ser = ser

        grid = Gtk.Grid()
        self.add(grid)

        self.button_fan0on = Gtk.Button(label="Fan ON")
        self.button_fan0on.connect("clicked", self.on_button_fan0on_clicked)
        self.button_fan0on.set_hexpand(True)
        self.button_fan0on.set_vexpand(True)

        self.button_fan0off = Gtk.Button(label="Fan OFF")
        self.button_fan0off.connect("clicked", self.on_button_fan0off_clicked)
        self.button_fan0off.set_hexpand(True)
        self.button_fan0off.set_vexpand(True)

        self.button_pump0on = Gtk.Button(label="Pump0 ON")
        self.button_pump0on.connect("clicked", self.on_button_pump0on_clicked)
        self.button_pump0on.set_hexpand(True)
        self.button_pump0on.set_vexpand(True)

        self.button_pump0off = Gtk.Button(label="Pump0 OFF")
        self.button_pump0off.connect("clicked", self.on_button_pump0off_clicked)
        self.button_pump0off.set_hexpand(True)
        self.button_pump0off.set_vexpand(True)

        self.button_pump1on = Gtk.Button(label="Pump1 ON")
        self.button_pump1on.connect("clicked", self.on_button_pump1on_clicked)
        self.button_pump1on.set_hexpand(True)
        self.button_pump1on.set_vexpand(True)

        self.button_pump1off = Gtk.Button(label="Pump1 OFF")
        self.button_pump1off.connect("clicked", self.on_button_pump1off_clicked)
        self.button_pump1off.set_hexpand(True)
        self.button_pump1off.set_vexpand(True)

        self.button_lighton = Gtk.Button(label="Light ON")
        self.button_lighton.connect("clicked", self.on_button_lighton_clicked)
        self.button_lighton.set_hexpand(True)
        self.button_lighton.set_vexpand(True)

        self.button_lightoff = Gtk.Button(label="Light OFF")
        self.button_lightoff.connect("clicked", self.on_button_lightoff_clicked)
        self.button_lightoff.set_hexpand(True)
        self.button_lightoff.set_vexpand(True)

        ad1 = Gtk.Adjustment(0, 0, 100, 5, 10, 0)
        self.scale_fanspeed = Gtk.Scale(orientation = Gtk.Orientation.HORIZONTAL, adjustment=ad1)
        self.scale_fanspeed.set_hexpand(True)
        self.scale_fanspeed.set_valign(Gtk.Align.START)
        self.scale_fanspeed.connect("value-changed", self.on_scale_fanspeed_moved)

        grid.add(self.button_fan0on)
        grid.attach_next_to(self.button_fan0off, self.button_fan0on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(self.button_pump0on, self.button_fan0on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(self.button_pump0off, self.button_pump0on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(self.button_pump1on, self.button_pump0on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(self.button_pump1off, self.button_pump1on, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(self.button_lighton, self.button_pump1on, Gtk.PositionType.RIGHT, 1, 1)
        grid.attach_next_to(self.button_lightoff, self.button_lighton, Gtk.PositionType.BOTTOM, 1, 1)
        grid.attach_next_to(self.scale_fanspeed, self.button_fan0off, Gtk.PositionType.BOTTOM, 1, 1)

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
