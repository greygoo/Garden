$(document).ready(function() {
  $("button").click(function(){
    setTimeout(() => {  $("#status").load("/status"); }, 300);
  })
})
