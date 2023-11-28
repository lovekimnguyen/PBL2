function myBtns() {
  var video = document.getElementById("video");
  var nut = document.getElementById("myBtn");
  var video1 = document.getElementById("video-fixed");
  if (video.paused) {
    video1.play();
    video.play();
    nut.innerHTML = "Dừng";
  } else {
    video.pause();
    video1.pause();
    nut.innerHTML = "Phát";
  }
}
var a = 1;
function day (){
let A = document.getElementById('hour').value;
let B = document.getElementById('day').value;
let C = document.getElementById('month').value;
let D = document.getElementById('year').value;
let E = document.getElementById('hour1').value;
let F = document.getElementById('day1').value;
let G = document.getElementById('month1').value;
let H = document.getElementById('year1').value;
let gio = document.getElementById('hour');
let hour = gio.options[gio.selectedIndex].text;
let ngay = document.getElementById('day');
let dayz = ngay.options[ngay.selectedIndex].text;
let thang = document.getElementById('month');
let month = thang.options[thang.selectedIndex].text;
let nam = document.getElementById('year');
let year = nam.options[nam.selectedIndex].text;
let gio1 = document.getElementById('hour1');
let hour1 = gio1.options[gio1.selectedIndex].text;
let ngay1 = document.getElementById('day1');
let day1 = ngay1.options[ngay1.selectedIndex].text;
let thang1 = document.getElementById('month1');
let month1 = thang1.options[thang1.selectedIndex].text;
let nam1 = document.getElementById('year1');
let year1 = nam1.options[nam1.selectedIndex].text;
let a = D + '- ' + C + '- ' + B ;
let b = H + '-' + G + '-' + F ;
    console.log(typeof a);
    console.log(typeof b);
    let day_start = new Date(a);
    let day_end = new Date(b);
    let time = get_day_of_time(day_start , day_end);
    if(time != null){
     document.getElementById("tu1").innerHTML = dayz;
     document.getElementById("tu2").innerHTML = month;
     document.getElementById("tu3").innerHTML = year ;
     document.getElementById("den1").innerHTML = day1 ;
     document.getElementById("den2").innerHTML = month1;
     document.getElementById("den3").innerHTML = year1 ;
     document.getElementById("result-table").innerHTML = time + ' ngày' ;
    }
     }
    function on (){
         alert("Button");
    }
    const get_day_of_time = (d1, d2) => {
    let ms1 = d1.getTime();
    let ms2 = d2.getTime();
    return Math.ceil((ms2 - ms1) / (24*60*60*1000));
    };
    function search(){
        alert("Không biết");
    }
    function fixed(){
      if(a == 1){
        document.getElementById("demo").innerHTML = "Bấm";
        document.getElementById("link").innerHTML = " vào đây";
        document.getElementById("after_link").innerHTML ="để xem cách làm ";
        a = 0;
      }
      else {
        document.getElementById("demo").innerHTML = "";
        document.getElementById("link").innerHTML = "";
        document.getElementById("after_link").innerHTML ="";
        a = 1;
      }
    }
    function red(){
        document.getElementById("change color").style.color = "red";
        document.getElementById("change color").style.fontSize = "40px";
    }