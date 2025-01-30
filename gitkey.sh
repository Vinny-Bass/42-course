#!/bin/bash

# Colors for better visibility
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Print banner
echo -e "${BLUE}====================================${NC}"
echo -e "${BLUE}  GitHub SSH Key Generation Script${NC}"
echo -e "${BLUE}====================================${NC}\n"

# Get user email
read -p "Enter your GitHub email address: " email

# Generate SSH key with ed25519 algorithm (more secure than RSA)
ssh-keygen -t ed25519 -C "$email" -f ~/.ssh/github_ed25519

# Start ssh-agent in the background
eval "$(ssh-agent -s)"

# Add SSH key to ssh-agent
ssh-add ~/.ssh/github_ed25519

# Copy public key to clipboard
pbcopy < ~/.ssh/github_ed25519.pub

echo -e "\n${GREEN}✔ SSH key has been generated successfully!${NC}"
echo -e "${GREEN}✔ Public key has been copied to your clipboard${NC}"
echo -e "\nNext steps:"
echo "1. Go to GitHub → Settings → SSH and GPG keys"
echo "2. Click 'New SSH key'"
echo "3. Paste your key (it's already in your clipboard)"
echo -e "\nTo test your connection, run: ${BLUE}ssh -T git@github.com${NC}"
