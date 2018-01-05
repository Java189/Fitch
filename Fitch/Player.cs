﻿using OpenTK;

namespace Fitch
{
    public struct Player
    {
        private Vector2 position;
        private float width;
        private float height;
        private Vector2 size;
        private Vector2 velocity;
        private bool running;
        private bool standing;
        private bool jumping;

        public Vector2 Position { get { return position; } set { position = value; } }
        public float Width { get { return width; }}
        public float Height { get { return height; }}
        public Vector2 Velocity { get { return velocity; } set { velocity = value; } }
        public Vector2 Size { get { return size; } }
        public bool isRunning { get { return running; } set { running = value; }}
        public bool isStanding { get { return standing; } set { standing = value; }}
        public bool isJumping { get { return jumping; } set { jumping = value; } }

        public Player(Vector2 position, float width, float height, Vector2 velocity, bool running = false, bool standing = false, bool jumping = false)
        {

            this.position = position;
            this.height = height;
            this.width = width;
            this.velocity = velocity;
            this.running = running;
            this.standing = standing;
            this.size = new Vector2(this.width, this.height);
            this.jumping = jumping;

        }
    }
}
