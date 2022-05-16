class Test {
    constructor(a) {
        this.a = a;
    }
    static plus(b, c) {
        this.b = b;
        this.c = c;
        console.log(this.b + this.c);
    }
}

Test.plus(3,4);