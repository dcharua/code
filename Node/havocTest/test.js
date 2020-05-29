$(document).ready(function() {
  $.ajax({
    type: 'GET',
    url: 'https://shrouded-inlet-99845.herokuapp.com/getCustomers',
      success: function(data) {
        console.log('suc');
          console.log(data);
      },
  error: function (err) {
        console.log('err');
         console.log(err)
      }
  });


  $.ajax({
    type: 'POST',
    url: 'https://shrouded-inlet-99845.herokuapp.com/getMeta',
    data: {customer_id: "2992658153577"},
      success: function(data) {
        console.log('suc');
          console.log(data[0].value);
      },
    error: function (err) {
        console.log('err');
         console.log(err)
      }
  });
});