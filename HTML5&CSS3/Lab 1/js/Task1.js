window.addEventListener("load", function () {
    let video = document.querySelector("video");
    video.volume = document.getElementById("sound").value;
    video.playbackRate = document.getElementById("speed").value;
    document.getElementById("timeBar").max = parseInt(video.duration);
    document.getElementById("timeBar").step = 1;
    document.getElementById("play").onclick = function () {
        video.play();
    }

    document.getElementById("stop").onclick = function () {
        video.pause();
    }

    document.getElementById("toStart").onclick = function () {
        video.currentTime = 0;
    }
    
    document.getElementById("back").onclick = function () {
        video.currentTime -= 5;
    }

    document.getElementById("next").onclick = function () {
        video.currentTime += 5;
    }

    document.getElementById("toEnd").onclick = function () {
        video.currentTime = video.duration;
    }

    document.getElementById("mute").onclick = function () {
        video.volume = 0;
        document.getElementById("sound").value = 0;

    }

    document.getElementById("sound").addEventListener("change", function(){
        video.volume = document.getElementById("sound").value;
    });

    document.getElementById("speed").addEventListener("change", function(){
        video.playbackRate = document.getElementById("speed").value;
    });

    document.getElementById("timeBar").addEventListener("change", function(){
        video.currentTime = document.getElementById("timeBar").value;
    });

    video.addEventListener("loadedmetadata", function () {
        const videoDuration = Math.round(video.duration);
        const time = formatTime(videoDuration);
        document.getElementById("full").innerText = `${time.minutes}:${time.seconds}`;
        document.getElementById("full").setAttribute('datetime', `${time.minutes}m ${time.seconds}s`)
    });

    video.addEventListener("timeupdate", function () {
        const time = formatTime(Math.round(video.currentTime));
        document.getElementById("timeBar").value = video.currentTime;
        document.getElementById("current").innerText = `${time.minutes}:${time.seconds}`;
        document.getElementById("current").setAttribute('datetime', `${time.minutes}m ${time.seconds}s`)
    });





    function formatTime(timeInSeconds) {
        const result = new Date(timeInSeconds * 1000).toISOString().substr(11, 8);

        return {
            minutes: result.substr(3, 2),
            seconds: result.substr(6, 2),
        };
    }

});