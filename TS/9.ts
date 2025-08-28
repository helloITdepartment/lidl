function isPalindrome(x: number): boolean {
    if (x < 0) {
        return false;
    }

    if (x == 0) {
        return true;
    }

    const numDigits = Math.log10(x);
    let digits: number[] = [];
    while (x > 0) {
        digits.push(x % 10);
        x = Math.floor(x/10);
    }

    for (let i = 0; i <= digits.length/2; i++) {
        if (digits[i] != digits[digits.length - i - 1]) {
            return false;
        }
    }
    return true;
};
