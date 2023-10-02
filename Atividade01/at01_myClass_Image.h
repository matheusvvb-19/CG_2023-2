class myClass_Image {
   private:
    int width = 256;

   private:
    int height = 256;

   public:
    void RenderImageFade(std::string filename);

   public:
    void RenderImageRectangule(std::string filename);

   public:
    void RenderImageLine(std::string filename);
};