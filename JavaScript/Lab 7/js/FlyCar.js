import { Car } from "./car.js";
export class FlyingCar extends Car {
    constructor(model, year, canFly = true) {
        super(model, year);
        this.canFly = canFly;
    }
    toString() {
        return `${super.toString()}
        I can fly: ${this.canFly}`;
    }
}