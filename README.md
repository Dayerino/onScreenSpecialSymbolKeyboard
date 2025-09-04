# 1.Description

a simple on screen keyboard which contains special symbols only, created with windows API

the inputs are sent using the symbols' Unicode & ANSI Codes

this started as an onscreen keyboard then i switched to special symbols because i found myself having to look up how to write certain buttons, this was modeled after my french AZERTY keyboard, so all the characters in here are ones i had on my keyboard, i realize i could add an infinite amount of buttons because there are thousands of them, so i picked the ones that were very commonly used.

# 2.How this project evolved

# 2.1 resizing buttons
at first i tried putting the buttons of each row in a vector in order to resize them to make them change dynamically, then i realised that doesnt really work since some of the parameters i used to calculate the space between the buttons couldn't be transfered(or were not convenient to use) so i went with a more tedious but working method of simply repositioning every button

# 2.2 the window size

at first the window size was static and hard coded, but i wanted to make the default size different depending on the user's screen resolution, i also added a minimum window width and height when resizing but made it a static value (550,200) to make sure the buttons are always on the window because when the window gets small enough buttons will start to be "eaten" out of the frame