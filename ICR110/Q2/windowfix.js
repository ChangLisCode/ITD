broken_window_count = 0
window_size = (x,y)
Total_area = 0

while 



let window = prompt('Did you broken your glass window? (yes , no)');
  let myBudge = prompt('How much is your budge?');
  let isfixed = 1;
  let findStore = 'false';

  if (window == 'yes') {
    while (isfixed >= 1) {
      let width = prompt('Measure the glass:\n Please enter width:');
      let heigth = prompt('Measure the glass:\n Please enter heigth:');
      let thickness = prompt('Measure the glass:\n Please enter thickness:');
      while (findStore == 'false') {
        let findGlass = prompt(
          'Call the store and ask if they have a glass window with: \n width: ' +
            width +
            '\nheigth: ' +
            heigth +
            '\nthickness: ' +
            thickness +
            '\n Do they have the glass? (yes, no)'
        );
        if (findGlass === 'yes') {
          let price = prompt('How much is the glass window?');
          if (price <= myBudge) {
            alert('Congratulations you bought a glass, now let install it');

            findStore = 'yes';
          } else {
            alert(
              'Sorry you are poor , I recommend you to use plastic or cardboard'
            );
            findStore = 'yes';
          }
        } else {
          alert('Please call to another store');
        }
      }
      isfixed = 0;
    }
  } else {
    alert('Good for you');
  }
