#include <stdio.h>
#include "src/canvas.h"
#include "src/ppmWriter.h"

struct Projectile {
    Tuple position;
    Tuple velocity;
};

struct Environment {
    Tuple gravity;
    Tuple wind;
};

struct Projectile tick(struct Environment env, struct Projectile projectile) {
    const f32_t resolution = 0.01f;
    projectile.velocity = mulScalarTuple(projectile.velocity,resolution);
    env.wind = mulScalarTuple(env.wind,resolution);
    env.gravity = mulColorScalar(env.gravity, resolution);
    Tuple position = addTuple(projectile.position, projectile.velocity);
    Tuple velocity = addTuple(divScalarTuple(projectile.velocity,resolution), addTuple(env.gravity, env.wind));
    return (struct Projectile) {position, velocity};
}

int main() {
    Canvas canvas = createCanvas(900, 550);
    Tuple start = createPoint(0, 1, 0);
    Tuple velocity = mulColorScalar(normalizeTuple(createVector(1, 1.8f, 0)), 11.25f);

    struct Projectile projectile = {start, velocity};
    struct Environment environment = {createVector(0, -0.1f, 0), createVector(-0.01f, 0, 0)};
    bool fellOutOfBounds = false;
    while (!fellOutOfBounds) {
        writePixel(canvas, projectile.position.x, canvas.height - projectile.position.y, (Color) {1, 1, 1});
        projectile = tick(environment, projectile);
        int x = projectile.position.x;
        int y = canvas.height - projectile.position.y;
        fellOutOfBounds = !isInBounds(canvas, x, y);
    }
    writeCanvasToPPM(canvas, "firstSimulation.ppm");
    return 0;
}
