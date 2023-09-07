const wifiIconOff = document.getElementById("wifi-off");
const wifiIconOn = document.getElementById("wifi-on");
const wifiText = document.getElementById("wifi-status");

const BLYNK_AUTH_TOKEN = "your-auth-token"; // replace "your-auth-token" with you Blynk Automation Token

// function to update the wifi status based on API response
function updateWifiState() {
    const apiUrl = "https://sgp1.blynk.cloud/external/api/isHardwareConnected?token=" + BLYNK_AUTH_TOKEN;

    // make AJAX request to API
    fetch(apiUrl)
        .then(response => response.text())
        .then(data => {
        // parse response and update wifi status
        const wifi = data.trim();
        if (wifi == 'true') {
            wifiIconOff.style.display = "none";
            wifiIconOn.style.display = "block";
            wifiText.innerText  = "Device Online";
            wifiText.style.color = "green";
        }
        else{
            wifiIconOff.style.display = "block";
            wifiIconOn.style.display = "none";
            wifiText.innerText  = "Device Offline";
            wifiText.style.color = "red";
        }
    })
    .catch(error => console.error(error));
}

// call the update function every 2 seconds
setInterval(updateWifiState, 2000);


// get the switch element
const switchElement1 = document.getElementById("switch1");

// function to update the switch state based on API response
function updateSwitchState1() {
const apiUrl = "https://sgp1.blynk.cloud/external/api/get?token=" + BLYNK_AUTH_TOKEN + "&v1";
// make AJAX request to API
fetch(apiUrl)
    .then(response => response.text())
    .then(data => {
    // parse response and update switch state
    const switchState = parseInt(data);
    // console.log(switchState);
    if (switchState === 0) {
        switchElement1.checked = true; // switch on
    } else {
        switchElement1.checked = false; // switch off
    }
    })
    .catch(error => console.error(error));
}

// call the update function every 2 seconds
setInterval(updateSwitchState1, 2000);


function toggleSwitch1() {
    // toggle
    if (switchElement1.checked) {
        // switch is turned on
        var url = "https://sgp1.blynk.cloud/external/api/update?token=" + BLYNK_AUTH_TOKEN + "&v1=0";
        var request = new XMLHttpRequest();
        request.open("GET", url);
        request.send();
    } else {
        // switch is turned off
        var url = "https://sgp1.blynk.cloud/external/api/update?token=" + BLYNK_AUTH_TOKEN + "&v1=1";
        var request = new XMLHttpRequest();
        request.open("GET", url);
        request.send();
    }
}
// get the switch element
const switchElement2 = document.getElementById("switch2");

// function to update the switch state based on API response
function updateSwitchState2() {
const apiUrl2 = "https://sgp1.blynk.cloud/external/api/get?token=" + BLYNK_AUTH_TOKEN + "&v2";
// make AJAX request to API
fetch(apiUrl2)
    .then(response => response.text())
    .then(data => {
    // parse response and update switch state
    const switchState = parseInt(data);
    // console.log(switchState);
    if (switchState === 0) {
        switchElement2.checked = true; // switch on
    } else {
        switchElement2.checked = false; // switch off
    }
    })
    .catch(error => console.error(error));
}

// call the update function every 2 seconds
setInterval(updateSwitchState2, 2000);

function toggleSwitch2() {
    // toggle
    if (switchElement2.checked) {
        // switch is turned on
        var url = "https://sgp1.blynk.cloud/external/api/update?token=" + BLYNK_AUTH_TOKEN + "&v2=0";
        var request = new XMLHttpRequest();
        request.open("GET", url);
        request.send();
    } else {
        // switch is turned off
        var url = "https://sgp1.blynk.cloud/external/api/update?token=" + BLYNK_AUTH_TOKEN + "&v2=1";
        var request = new XMLHttpRequest();
        request.open("GET", url);
        request.send();
    }
}
