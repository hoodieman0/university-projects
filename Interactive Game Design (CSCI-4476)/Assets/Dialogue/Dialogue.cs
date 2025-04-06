using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Dialogue", menuName = "Dialogue")]
public class Dialogue : ScriptableObject
{
    public  AudioClip    audioClip;
    public  string       subtitle;
    public  string       speaker;
    public  float        delayBefore;
    public  float        delayAfter;
}
