require 'rufus-scheduler'
require 'yaml'

class SCHEDULER

  def initialize
    @scheduler 	= Rufus::Scheduler.new


    # default scheduler values
      default_scheduler_config = {
      'pump0_interval' 	=> '5m',
      'pump0_on' 	=> '2s',
      'pump1_interval' 	=> '1h',
      'pump1_on' 	=> '5s',
      'light_on' 	=> '00 06 * * *',
      'light_off'	=> '00 00 * * *'
    }

    # merge config file values into defaults
    @scheduler_config = default_scheduler_config.merge(YAML.load_file("config.yml"))
    puts @scheduler_config

    @job = {}


    # schedule default jobs
    @job["pump0"] = @scheduler.schedule_every(@scheduler_config["pump0_interval"], :discard_past => true) do
      puts "turn on pump0"
      $i.send("pump0on")
      sleep @scheduler_config["pump0_on"].gsub("s","").to_i
      puts "turn off pump0"
      $i.send("pump0off")
    end

    @job["pump1"] = @scheduler.schedule_every(@scheduler_config["pump1_interval"], :discard_past => true) do
      puts "turn on pump1"
      $i.send("pump1on")
      sleep @scheduler_config["pump1_on"].gsub("s","").to_i
      puts "turn off pump1"
      $i.send("pump1off")
    end

    @job["light"] = @scheduler.schedule_cron @scheduler_config["light_on"] do
      puts "turn on light"
    end

    @job["light"] = @scheduler.schedule_cron @scheduler_config["light_off"] do
      puts "turn off light"
    end
  end


  def set(unit, on, off)

  end


  def stop(unit)
    puts "Stopping scheduling for #{unit}"
    @job[unit].pause if ! @job[unit].paused?
  end


  def start(unit)
    puts "Starting scheduling for #{unit}"
    @job[unit].kill
    @job[unit].resume if @job[unit].paused?
  end
end
