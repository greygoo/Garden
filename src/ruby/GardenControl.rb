require 'rubygems'
require 'sinatra'
require_relative './Garden'

get '/' do
  redirect '/gardencontrol'
end

get '/gardencontrol' do
  "Garden control interface"
  erb :control
end

get "/status" do
  "Status: " + $status
end

post "/control" do
  puts " parameter is: #{params[:command]}"
  if params[:command] == "connect"
    puts "Connecting to Garden"
    $i = GARDEN.new() 
  elsif params[:command] == "disconnect"
    puts "Disconnecting from Garden"
    $i.disconnect
  end
end

post "/commands" do
  puts " parameter is: #{params[:command]}"
  $i.send(params[:command])
end

get '/test' do
  stream do |out|
    out << "It's gonna be legen -\n"
    sleep 10 
    out << " (wait for it) \n"
    sleep 10
    out << "- dary!\n"
  end
end
