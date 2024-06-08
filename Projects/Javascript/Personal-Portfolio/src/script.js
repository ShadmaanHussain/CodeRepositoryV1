// Navigation

(function navigation() {
  const burgerBtn = document.querySelector(".burger"); // burger button
  const navLinks = document.querySelector(".nav-links"); //ul of the navbar
  const body = document.querySelector("body"); // body of the html

  function toggleNav() {
    navLinks.classList.toggle("nav-active");
    burgerBtn.classList.toggle("burger-active");
    body.classList.toggle("no-scroll");
  }

  // Toggle the navbar using the burger button.
  burgerBtn.addEventListener("click", function () {
    toggleNav();
  });

  // Close the navbar and remove no-scroll after the navigation links are clicked.
  navLinks.addEventListener("click", function (e) {
    if (e.target.tagName === "A" && window.innerWidth < 650) {
      toggleNav();
    }
  });
}());

// Typewriter Effect
(function typewriter() {
    const skills = ["eat.", "sleep.", "code.", "workout.", "play games.", "watch tv series.", "be awsome."];
    let count = 0;
    let index = 0;
    function type() {
        if(index === skills.length) {
            index = 0;
        }
        const typeSpace = document.querySelector('#type');
        let currentWord = skills[index];
        let currentLetter = currentWord.slice(0, ++count);
        typeSpace.textContent = currentLetter;
        if(count === currentWord.length + 1) {
            count = 0;
            index++;
            typeSpace.textContent = "";
        }
    }
    setInterval(type, 200);
}());
