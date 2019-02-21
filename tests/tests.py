#!/usr/bin/env python3

import unittest
import subprocess


class TestSuite(unittest.TestCase):

    def test_hello_world(self):
        self.assertEqual('test', 'test')

    def test_subprocess(self):
        ret1 = subprocess.run(["ls", "-l"],
                              stdout=subprocess.PIPE,
                              stderr=subprocess.PIPE)

        ret2 = subprocess.run(["ls", "-l"],
                              stdout=subprocess.PIPE,
                              stderr=subprocess.PIPE)

        self.assertEqual(ret1.returncode, ret2.returncode)
        self.assertEqual(ret1.stdout, ret2.stdout)
        self.assertEqual(ret1.stderr, ret2.stderr)

unittest.main()