$(document).ready(function() {
  $(".commands").click(function(e){
    var command=$(this).data("cmd")
    $.post( "commands", { command: command } )
  })
})
