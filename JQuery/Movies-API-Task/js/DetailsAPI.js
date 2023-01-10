$(()=>{
    let movieID = location.search.split("=")[1];
    let imgsUrl = "https://image.tmdb.org/t/p/w500/";
    let url = `https://api.themoviedb.org/3/movie/${movieID}?api_key=9813ce01a72ca1bd2ae25f091898b1c7`;
    $.get(url, function(data){
        $(`<div class="container">
            <img src="${imgsUrl + data.poster_path}" alt="Move" />
            <div>
                <h3 id="moveName">${data.title}</h3>
                <p>${data.overview}</p>
            </div>
        </div>`).appendTo("#movieData");
    })    
});