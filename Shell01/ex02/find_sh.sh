find . -depth -type f -name "*.sh" ! -name ".sh" -exec basename {} .sh ';'
