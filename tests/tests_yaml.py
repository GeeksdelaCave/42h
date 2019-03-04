#!/usr/bin/env python3

import subprocess
import yaml



def run(cmd):
    return subprocess.run(cmd,
                          shell=True,
                          encoding='utf-8',
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE)


def set_color(color):
    return "\e[0m" if color == 'RESET' else "\033[" + color_dict[color] + "m"


with open("tests_yaml.yml", "r") as f:
    tests = yaml.load(f)

for test, data in tests.items():
    ref = run("bash --posix -c '" + data["ref"] + "'")
    cmd = run("bash --posix -c '" + data["cmd"] + "'")

    #  Listing des erreurs qui sont arrivés
    errors = []
    if ref.stdout != cmd.stdout:
        errors.append("STDOUT")
    if ref.stderr != cmd.stderr:
        errors.append("STDERR")
    if ref.returncode != cmd.returncode:
        errors.append("RETURN CODE")

    res = "ERROR" if errors else "OK"
    print("{id}: {desc} [{res}]".format(id=test, desc=data["desc"], res=res))

    # decode() convertit des bytes en str
    if "STDOUT" in errors:
        print("\t", "stdout returned: " + cmd.stdout, end='')
        print("\t", "stdout expected: " + ref.stdout, end='')

    if "STDERR" in errors:
        print("\t", "stderr returned: " + cmd.stderr, end='')
        print("\t", "stderr expected: " + ref.stderr, end='')

    if "RETURN CODE" in errors:
        print("\t", "return code returned: " + cmd.returncode, end='')
        print("\t", "return code expected: " + ref.returncode, end='')
