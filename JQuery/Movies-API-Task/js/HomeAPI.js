$(() => {
    let apiUrl = "https://api.themoviedb.org/3/discover/movie?sort_by=popularity.desc&api_key=9813ce01a72ca1bd2ae25f091898b1c7";
    let imgsUrl = "https://image.tmdb.org/t/p/w500/";

    $.get(apiUrl, function (data) {
        data.results.forEach(movie => {
            $(`<div class="movie">
            <a href="./DetailsPage.html?id=${movie.id}">
                <img src="${imgsUrl + movie.poster_path}" alt="Move" />
                <h4 id="moveName">${movie.title}</h4>
             </a>
            </div>`).appendTo("#main");

        });
    })
});
