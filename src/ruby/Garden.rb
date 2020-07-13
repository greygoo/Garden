#!/usr/bin/ruby

require 'serialport'
require_relative 'Scheduler'

class GARDEN

  def initialize()
    # init some vars
    $status = "starting up"

    # init serial connection
    puts "Connecting to serial port"
    @serial_port = SerialPort.new "/dev/ttyUSB0", 115200 
    @serial_port.read_timeout = 5000

    puts "Creating scheduler"
    @jobs = SCHEDULER.new


    # function reading serial port in a loop
    def check_serial(callback)
      #begin
	puts "Start serial read thread"
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
      puts "Turning on Light 0 and pause auto mode"
      @jobs.stop('light')
      @serial_port.puts "cL\n"
    when "light0off"
      puts "Turning off Light 0 and pause auto mode"
      @jobs.stop('light')
      @serial_port.puts "cl\n"
    when "light0auto"
      puts "Switching Light 0 to automatic mode"
      @jobs.start('light')

    when "pump0on"
      puts "Turning on Pump 0"
      @jobs.stop('pump0')
      @serial_port.write "cP0\n"
    when "pump0off"
      puts "Turning off Pump 0"
      @jobs.stop('pump0')
      @serial_port.write "cp0\n"
    when "pump0auto"
      puts "Switching Pump 0 to automatic mode"
      @jobs.start('pump0')

    when "pump1on"
      puts "Turning on Pump 1"
      @jobs.stop('pump1')
      @serial_port.write "cP1\n"
    when "pump1off"
      puts "Turning off Pump 1"
      @jobs.stop('pump1')
      @serial_port.write "cp1\n"
    when "pump1auto"
      puts "Switching Pump 1 to automatic mode"
      @jobs.start('pump1')

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

