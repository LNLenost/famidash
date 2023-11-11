char bg_collision_sub(void){
    if(temp_y >= 0xf0) return 0;
    
	coordinates = (temp_x >> 4) + (temp_y & 0xf0);
    // we just need 4 bits each from x and y
	
	collision = collisionMap0[coordinates];
	
    return collision;
}



char bg_coll_L(void){
    // check 2 points on the left side
    temp_x = Generic.x;
    
    eject_L = temp_x | 0xf0;
	tmp1 = Generic.y + 2;
	tmp5 = add_scroll_y(tmp1, scroll_y);
	temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    if(bg_collision_sub() ) return 1;
    
    tmp1 = Generic.y + Generic.height;
    tmp1 -= 2;
	tmp5 = add_scroll_y(tmp1, scroll_y);
	temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    if(bg_collision_sub() ) return 1;
    
    return 0;
}

char bg_coll_R(void){
    // check 2 points on the right side
	temp_x = Generic.x + Generic.width;
    
    eject_R = (temp_x + 1) & 0x0f;
	tmp1 = Generic.y + 2;
	tmp5 = add_scroll_y(tmp1, scroll_y);
	temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    if(bg_collision_sub() ) return 1;
    
    tmp1 = Generic.y + Generic.height;
    tmp1 -= 2;
	tmp5 = add_scroll_y(tmp1, scroll_y);
	temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    if(bg_collision_sub() ) return 1;
    
    return 0;
}

char bg_coll_U(void){
    // check 2 points on the top side
    temp_x = Generic.x;
    
	tmp1 = Generic.y;
	tmp5 = add_scroll_y(tmp1, scroll_y); 
    temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    eject_U = temp_y | 0xf0;
    if(bg_collision_sub() ) return 1;
    
    temp_x = Generic.x + Generic.width;
	temp_x -= 2;
    
    if(bg_collision_sub() ) return 1;
    
    return 0;
}

char bg_coll_D(void){
    // check 2 points on the bottom side
	temp_x = Generic.x;
    
	tmp1 = Generic.y + Generic.height;
	tmp5 = add_scroll_y(tmp1, scroll_y);
    temp_y = (char)tmp5; // low byte
	temp_room = tmp5 >> 8; // high byte
    eject_D = (temp_y + 1) & 0x0f;
    if(bg_collision_sub() ) return 1;
    
    temp_x = Generic.x + Generic.width;
	temp_x -= 2;
    
    if(bg_collision_sub() ) return 1;
    
    return 0;
}



char bg_coll_D2(void){
    // check 2 points on the bottom side
    // a little lower, for jumping
    tmp5 = Generic.x + scroll_x;
    tmp5 += 2;
    temp_x = (char)tmp5; // low byte

    temp_y = Generic.y + Generic.height;
    temp_y += 2;
    if(bg_collision_sub() & COL_ALL) {cube_rotate = 0x0080; return 1;}

    tmp5 = Generic.x + scroll_x + Generic.width;
    tmp5 -= 2;
    temp_x = (char)tmp5; // low byte
    
    if(bg_collision_sub() & COL_ALL) {cube_rotate = 0x0080; return 1;}
    
	

    return 0;
}

char bg_coll_U2(void){
    // check 2 points on the bottom side
    // a little lower, for jumping
    tmp5 = Generic.x + scroll_x;
    tmp5 += 2;
    temp_x = (char)tmp5; // low byte

    temp_y = Generic.y;
    temp_y -= 2;
    if(bg_collision_sub() & COL_ALL) {cube_rotate = 0x0080; return 1;}

    tmp5 = Generic.x + scroll_x + Generic.width;
    tmp5 -= 2;
    temp_x = (char)tmp5; // low byte
    
    if(bg_collision_sub() & COL_ALL) {cube_rotate = 0x0080; return 1;}
    
	

    return 0;
}



