#!/usr/bin/env python3

import unittest
import subprocess

# Color dictionary
color_dict = {
    'RED': '31',
    'GREEN': '32',
    'YELLOW': '33',
    'BLUE': '34',
    'L_GRAY': '37',
    'L_RED': '91',
    'L_GREEN': '92',
    'L_YELLOW': '93',
    'L_BLUE': '94',
    'WHITE': '97'
}



# Change output color
def set_color(color):
    return "\033[0m" if (color == 'RESET') else "\033[" + color_dict[color] + "m"

class TestSuite(unittest.TestCase):

    def test_hello_world(self):
        self.assertEqual('test', 'test')


if __name__ == "__main__":
    print(f'\n\n{set_color("L_YELLOW")}Launching tests UNIT{set_color("RESET")}\n')
    unittest.main()
