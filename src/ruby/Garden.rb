#!/usr/bin/ruby

require 'serialport'

class GARDEN

  def initialize()
    # init serial connection
    puts "Connecting to serial port"
    @serial_port = SerialPort.new "/dev/ttyUSB0", 115200 
    @serial_port.read_timeout = 5000

    # function reading serial port in a loop
    def check_serial(callback)
      #begin
        Thread.new do
          while true
            if (input = @serial_port.gets)
              unless input.empty?
                callback.call(input)
              end
            end
          end
        end
      #rescue
      #end
    end


    def serial_callback(input)
      puts input
      $status = input
    end

    check_serial(method(:serial_callback))
  end


  def disconnect
    # close serial connection
    @serial_port.close
  end

  def send(command)
    case command
    when "light0on"
      puts "Turning on Light 0"
      @serial_port.puts "cL\n"
    when "light0off"
      puts "Turning off Light 0"
      @serial_port.write "cl\n"
    when "light0auto"
      puts "Switching Light 0 to automatic mode"
      # turn on automatic

    when "pump0on"
      puts "Turning on Pump 0"
      @serial_port.write "cP0\n"
    when "pump0off"
      puts "Turning off Pump 0"
      @serial_port.write "cp0\n"
    when "pump0auto"
      puts "Switching Pump 0 to automatic mode"
      # turn on automatic

    when "pump1on"
      puts "Turning on Pump 1"
      @serial_port.write "cP1\n"
    when "pump1off"
      puts "Turning off Pump 1"
      @serial_port.write "cp1\n"
    when "pump1auto"
      puts "Switching Pump 1 to automatic mode"
      # turn on automatic

    when "fan0on"
      puts "Turning on Fan 0"
      @serial_port.write "cF0\n"
    when "fan0off"
      puts "Turning off Fan 0"
      @serial_port.write "cf0\n"
    when "fan0auto"
      puts "Switching Fan 0 to automatic mode"
      # turn on automatic

    when "fan1on"
      puts "Turning on Fan 1"
      @serial_port.write "cF1\n"
    when "fan1off"
      puts "Turning off Fan 1"
      @serial_port.write "cf1\n"
    when "fan1auto"
      puts "Switching Fan 1 to automatic mode"
      # turn on automatic
    end
  end
end

