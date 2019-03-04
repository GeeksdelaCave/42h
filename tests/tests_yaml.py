#!/usr/bin/env python3

import subprocess
import yaml


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


# Launch process in child process
def run(cmd):
    return subprocess.run(cmd,
                          shell=True,
                          encoding='utf-8',
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE)


def main():
    with open("tests/tests_yaml.yml", "r") as f:
        tests = yaml.load(f)

    ok = 0
    ko = 0

    for test, data in tests.items():
        ref = run("bash --posix -c '" + data["ref"] + "'")
        cmd = run("./42sh -c " + data["cmd"] + "'")

        errors = []
        if ref.stdout != cmd.stdout:
            errors.append("STDOUT")
        if ref.stderr != cmd.stderr:
            errors.append("STDERR")
        if ref.returncode != cmd.returncode:
            errors.append("RETURN CODE")

        # OK in green or ERROR in red
        if (errors):
            res = set_color('L_RED') + "[ERROR]"
            ko += 1
        else:
            res = set_color('L_GREEN') + "[OK]"
            ok += 1

        # Output
        log = f'  {set_color("L_YELLOW")}{test:13} {set_color("L_GRAY")}{data["desc"]:50} {res:12}{set_color("RESET")}'
        print(log)

        if "STDOUT" in errors:
            print(f'\t\t{set_color("RED")}stdout returned: {set_color("WHITE")}'
                  + cmd.stdout, end='')
            print(f'\t\t{set_color("GREEN")}stdout expected: {set_color("WHITE")}'
                  + ref.stdout, end='')

        if "STDERR" in errors:
            print(f'\t\t{set_color("RED")}stderr returned: {set_color("WHITE")}'
                  + cmd.stderr, end='')
            print(f'\t\t{set_color("GREEN")}stderr expected: {set_color("WHITE")}'
                  + ref.stderr, end='')

        if "RETURN CODE" in errors:
            print(f'\t\t{set_color("RED")}return code returned: {set_color("WHITE")}'
                  + cmd.returncode, end='')
            print(f'\t\t{set_color("GREEN")}return code expected: {set_color("WHITE")}'
                  + ref.returncode, end='')

    print(f'\n\nRan {set_color("YELLOW")}{ok + ko}{set_color("RESET")} tests.')
    print(f'{ok}{set_color("GREEN")} passed{set_color("RESET")} ({(ok * 100) // (ko + ok)}.{ok % (ko + ok) * 100 // 100}%)')
    print(f'{ko}{set_color("RED")} failed{set_color("RESET")} ({(ko * 100) // (ko + ok)}.{ko % (ko + ok) * 100 // 100}%)')

if __name__ == "__main__":
    print(f'\n\n{set_color("RED")}Launching tests YAML{set_color("RESET")}\n')
    main()