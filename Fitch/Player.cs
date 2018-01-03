﻿using System;
using OpenTK;

namespace Fitch
{
    public struct Player
    {
        private Vector2 position;
        private float width;
        private float height;
        private Vector2 velocity;
        private bool running;

        public Vector2 Position { get { return position; } set { position = value; } }
        public float Width { get { return width; }}
        public float Height { get { return height; }}
        public Vector2 Velocity { get { return velocity; } set { velocity = value; } }
        public bool isRunning { get { return running; } set { running = value; }}

        public Player(Vector2 position, float width, float height, Vector2 velocity, bool running)
        {

            this.position = position;
            this.height = height;
            this.width = width;
            this.velocity = velocity;
            this.running = running;

        }
    }
}
