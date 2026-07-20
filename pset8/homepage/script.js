document.addEventListener('DOMContentLoaded', function() {
    const facts = [
        "Currently working through CS50x while building a content brand.",
        "Certified in Cisco CCNA and Google Cybersecurity.",
        "Deadpan on Instagram, still not here to be liked.",
        "Focused on cybersecurity as a career path."
    ];

    const btn = document.querySelector('#quote-btn');
    const output = document.querySelector('#quote-output');

    if (btn) {
        btn.addEventListener('click', function() {
            const randomFact = facts[Math.floor(Math.random() * facts.length)];
            output.textContent = randomFact;
        });
    }
});
