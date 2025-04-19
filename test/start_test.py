import os

def create_folder(relative_path: str) -> str:
    abs_path: str = os.path.abspath(relative_path)
    if not os.path.exists(abs_path):
        os.makedirs(abs_path)
    return abs_path

def call_cmd(cmd: str, argv: str) -> None:
    path: str = create_folder(f"examples/{cmd}")
    os.system(f"start OpenIPL-CLI.exe ./src.png {path}/out.png {cmd} {argv}")

def main() -> None:
    call_cmd("-turn90", "")
    call_cmd("-negative", "")
    call_cmd("-sepia", "")
    call_cmd("-sharpen", "")
    call_cmd("-mirror", "")

    call_cmd("-bright", "0.5")
    call_cmd("-contrast", "0.5")
    call_cmd("-grayscale", "1.0")
    call_cmd("-blackwhite", "0.5")

    call_cmd("-addtext", "432 1000 Hello_World 100 ./font.ttf 255 255 255")
    call_cmd("-biinterpolation", "512 512")
    call_cmd("-gauss", "50")

if __name__ == "__main__":
    main()