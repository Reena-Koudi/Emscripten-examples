var app = null;

var script = document.createElement('script');

const onKey = (key, callback) => {
    document.addEventListener('keydown', (event) => {
        if (event.keyCode == key.toUpperCase().charCodeAt(0) || event.keyCode == key.toLowerCase().charCodeAt(0)) {
            callback();
        }
    });
}

script.onload = (e) => {

    var canvas = document.createElement('canvas');
    canvas.width = 512;
    canvas.height = 512;

    document.body.appendChild(canvas);

    app = new GLApp({
        canvas: canvas,
        print: function (e) {
            //std::cout redirects to here
            console.log(e);
        },
        onRuntimeInitialized: function (e) {

            app.init("");
            app.render();
        }
    });
}

onKey('a', () => { 
    app.translateX(-0.1); 
    app.render();
});
onKey('d', () => {
    app.translateX(0.1);
    app.render();
});

function updateLoop(dt) {

    app.render();
    window.requestAnimationFrame(updateLoop);
}

script.setAttribute('src', 'GLApp.js');

document.body.appendChild(script);